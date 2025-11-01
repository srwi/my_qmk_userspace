#!/usr/bin/env python3

import argparse
from pathlib import Path
import shutil
import subprocess
import sys


# List of vendor folders that need to be copied from this userspace into qmk_firmware
CUSTOM_VENDOR_FOLDERS = ["srwi"]


def parse_args() -> argparse.Namespace:
    prog = Path(sys.argv[0]).name
    parser = argparse.ArgumentParser(prog=prog, description="Compile QMK firmware for a given keyboard and keymap.")
    parser.add_argument("--keyboard", dest="keyboard", required=True, help="keyboard (e.g. srwi/like_lily58)")
    parser.add_argument("--keymap", dest="keymap", default="default", help="keymap name (default: default)")
    parser.add_argument("--overwrite", dest="overwrite", action="store_true", help="overwrite existing destination")
    return parser.parse_args()


def copy_vendor_folder(vendor: str, overwrite: bool) -> None:
    src_vendor_dir = Path(__file__).parent / "keyboards" / vendor
    dest_vendor_dir = Path(__file__).parent / "qmk_firmware" / "keyboards" / vendor

    if not src_vendor_dir.is_dir():
        print(f"Error: source vendor folder not found: {src_vendor_dir}", file=sys.stderr)
        return 1

    if dest_vendor_dir.exists():
        if overwrite:
            print(f"Overwriting existing folder: {dest_vendor_dir}")
            shutil.rmtree(dest_vendor_dir)
        else:
            print(f"Error: destination vendor folder already exists: {dest_vendor_dir}")
            print("Use -overwrite to replace it.")
            return 1

    print(f"Copying {src_vendor_dir} -> {dest_vendor_dir}")
    dest_vendor_dir.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(str(src_vendor_dir), str(dest_vendor_dir), symlinks=True, copy_function=shutil.copy2)


def main() -> int:
    args = parse_args()
    keyboard = args.keyboard
    keymap = args.keymap
    overwrite = bool(args.overwrite)

    vendor = keyboard.split("/", 1)[0] if keyboard else ""
    if not vendor:
        print("Error: could not determine vendor from keyboard string", file=sys.stderr)
        return 1

    if vendor in CUSTOM_VENDOR_FOLDERS:
        copy_vendor_folder(vendor, overwrite)

    cmd = ["qmk", "compile", "-kb", keyboard, "-km", keymap]
    print("Running", " ".join(cmd))

    proc = subprocess.run(cmd)

    if proc.returncode != 0:
        print(f"qmk compile failed with exit code {proc.returncode}")
    else:
        print("qmk compile succeeded")

    return proc.returncode


if __name__ == "__main__":
    raise SystemExit(main())
