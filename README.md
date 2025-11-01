# QMK Userspace

Collection of QMK based keyboards including stl files for 3D-printing.

## Keyboards

- Handwired
    - [srwi/like_lily58](keyboards/srwi/like_lily58) - 3D-printed/painted split keyboard inspired by the Lily58
    - [srwi/like_vortex_core](keyboards/srwi/like_vortex_core) - 3D-printed/painted 40% keyboard with the layout of the Vortex Core
    - [srwi/like_planck](keyboards/srwi/like_planck) - 3D-printed transparent keyboard with 3D-printed keycaps with the layout of the Planck
    - [srwi/silico](keyboards/srwi/silico) - Handwired 60% keyboard embedded into solid silicone in an aluminum case and 3D-printed plate
- Vendor keyboards
    - [crkbd/rev1](keyboards/crkbd/keymaps/srwi) - Corne keyboard with a transparent 3D-printed case and flat choc switches
    - [evyd13/plain60](keyboards/evyd13/plain60/keymaps/srwi) - Evyd13 Plain60 keyboard with plate and stabilizers taken from an old Vortex Pok3r (ISO)
    - [ymdk/yd60mq #1](keyboards/ymdk/yd60mq/keymaps/srwi) - YMDK YD60MQ 60% keyboard in a wooden case with brass inlet
    - [ymdk/yd60mq #2](keyboards/ymdk/yd60mq/keymaps/srwi_split_spacebar) - YMDK YD60MQ 60% keyboard with split spacebar

## Building custom/handwired keyboards

Regular QMK userspace does not support custom/handwired keyboards. For being able to build them anyway, we need to clone the qmk firmware repository here, configure it for use with this userspace, and add the custom keyboard keymaps before building:

### Building with GitHub Actions

Keyboard firmwares will be built automatically on push to the repository and uploaded as workflow artifacts.

### Building manually

In Codespaces `.devcontainer/setup.sh` will be run automatically to set up the environment for compiling custom/handwired keyboards. Locally, the corresponding setup needs to be done manually.

Once everything is set up, existing vendor's keyboards can be built normally using the qmk cli. Custom/handwired keyboards have to be built using the python script `compile_keyboard.py` which will copy the vendor directory into the qmk_firmware clone before building:

    `python compile_keyboard.py --keyboard <keyboard> --keymap <keymap> [--overwrite]`

Currently the only custom vendor is `srwi`, but it can be extended by adding more vendors to `CUSTOM_VENDOR_FOLDERS` in `compile_keyboard.py`.

-----------

<details>

<summary>Original QMK userspace readme</summary>

This is a template repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the main QMK repository.

## Howto configure your build targets

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Fork this repository
1. Clone your fork to your local machine
1. Enable userspace in QMK config using `qmk config user.overlay_dir="$(realpath qmk_userspace)"`
1. Add a new keymap for your board using `qmk new-keymap`
    * This will create a new keymap in the `keyboards` directory, in the same location that would normally be used in the main QMK repository. For example, if you wanted to add a keymap for the Planck, it will be created in `keyboards/planck/keymaps/<your keymap name>`
    * You can also create a new keymap using `qmk new-keymap -kb <your_keyboard> -km <your_keymap>`
    * Alternatively, add your keymap manually by placing it in the location specified above.
    * `layouts/<layout name>/<your keymap name>/keymap.*` is also supported if you prefer the layout system
1. Add your keymap(s) to the build by running `qmk userspace-add -kb <your_keyboard> -km <your_keymap>`
    * This will automatically update your `qmk.json` file
    * Corresponding `qmk userspace-remove -kb <your_keyboard> -km <your_keymap>` will delete it
    * Listing the build targets can be done with `qmk userspace-list`
1. Commit your changes

## Howto build with GitHub

1. In the GitHub Actions tab, enable workflows
1. Push your changes above to your forked GitHub repository
1. Look at the GitHub Actions for a new actions run
1. Wait for the actions run to complete
1. Inspect the Releases tab on your repository for the latest firmware build

## Howto build locally

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Fork this repository
1. Clone your fork to your local machine
1. `cd` into this repository's clone directory
1. Set global userspace path: `qmk config user.overlay_dir="$(realpath .)"` -- you MUST be located in the cloned userspace location for this to work correctly
    * This will be automatically detected if you've `cd`ed into your userspace repository, but the above makes your userspace available regardless of your shell location.
1. Compile normally: `qmk compile -kb your_keyboard -km your_keymap` or `make your_keyboard:your_keymap`

Alternatively, if you configured your build targets above, you can use `qmk userspace-compile` to build all of your userspace targets at once.

## Extra info

If you wish to point GitHub actions to a different repository, a different branch, or even a different keymap name, you can modify `.github/workflows/build_binaries.yml` to suit your needs.

To override the `build` job, you can change the following parameters to use a different QMK repository or branch:
```
    with:
      qmk_repo: qmk/qmk_firmware
      qmk_ref: master
```

If you wish to manually manage `qmk_firmware` using git within the userspace repository, you can add `qmk_firmware` as a submodule in the userspace directory instead. GitHub Actions will automatically use the submodule at the pinned revision if it exists, otherwise it will use the default latest revision of `qmk_firmware` from the main repository.

This can also be used to control which fork is used, though only upstream `qmk_firmware` will have support for external userspace until other manufacturers update their forks.

1. (First time only) `git submodule add https://github.com/qmk/qmk_firmware.git`
1. (To update) `git submodule update --init --recursive`
1. Commit your changes to your userspace repository

</details>
