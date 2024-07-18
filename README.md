# Control Light brightness by software PWM

Control the LED brightness with a software PWM which is created by PIT module.

## Built With

* [Kinetis Design Studio IDE](https://www.nxp.com/design/design-center/development-boards-and-designs/design-studio-integrated-development-environment-ide:KDS_IDE) - The IDE used.
* [FRDM-KL46Z](https://www.nxp.com/design/design-center/development-boards-and-designs/general-purpose-mcus/freedom-development-platform-for-kinetis-kl3x-and-kl4x-mcus:FRDM-KL46Z) - The Kit used.

## Versioning

Ver 0.0

## Authors

* **Nguyen The Anh** - [AnhNT2920](https://github.com/AnhNT2920)

## License

This project is public for use.

## Important notes

* This program works on the FRD-MKL46Z kit.
* Control the LED brightness based on environment light density.
* PIT and ADC modules are used to serve the program.
* PWM resolution is 100 (Duty cycle has value in the range of 0% to 100%)
* PWM has 1kHz frequency.
