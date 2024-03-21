This repo contains extracted files from [latest avalible LineageOS 18.1](https://sourceforge.net/projects/dereferenceroms/files/miatoll/los18/lineage-18.1-20220902-nightly-miatoll-signed.zip/download)
---
## Extraction process
1. Unzip fw
2. Unpack it with brotli
3. Use [sdat2img](https://github.com/xpirt/sdat2img) to get img files
4. Mount them in apropriate tree:
```
mkdir system/
sudo mount ~/images/system.img system/
sudo mount ~/images/vendor.img system/vendor/
sudo mount ~/images/system_ext.img system/system_ext/
sudo mount ~/images/product.img system/product/
```
5. Run extraction script ```sudo -E ./droid-system-device/helpers/copy_tree.sh ./system/ rpm/droid-system-miatoll.spec``` I had to run it as root due apex partition permissions.
Because I ran it's as root I also had to pachage it in sfossdk as root and restore zypper db permissions then)
