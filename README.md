# Setting Up QMK

``` bash
yay -S qmk-git

qmk setup
qmk list-keyboards

# Build default to try
qmk compile -kb preonic/rev3_drop -km default
qmk config user.keyboard=preonic/rev3_drop

# Create own keymap
qmk new-keymap
qmk compile -kb preonic/rev3_drop -km Vi3Programming

# Set keyboard in flashing mode (press the reset button from under the keyboard): 
qmk flash -kb preonic/rev3_drop -km Vi3Programming
```
