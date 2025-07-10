# RGB to HA PixInsight Plugin

A professional PixInsight plugin that converts RGB images to Hydrogen Alpha (HA) with advanced image processing algorithms and improved image quality.

## Features

- **Multiple Conversion Algorithms**: Spectral coefficient-based conversion, adaptive histogram matching, and neural network enhancement
- **Advanced Image Processing**: Noise reduction, sharpening, and color balance optimization
- **Professional GUI**: Intuitive interface with real-time preview and parameter controls
- **Cross-Platform**: Universal binary support for Intel Macs, Apple Silicon, and x64 CPUs
- **One-Click Installation**: Install directly through PixInsight's Updates tab

## Installation

### Method 1: PixInsight Updates (Recommended)

1. Open PixInsight
2. Go to **Resources** → **Updates** → **Manage Repositories**
3. Click **Add** and enter the repository URL:
   ```
   https://connrcodes.github.io/RGB_TO_HA/repository-server.xml
   ```
4. Click **OK** to save
5. Go to **Updates** tab and click **Check for Updates**
6. Find "RGB to HA" in the list and click **Install**

### Method 2: Manual Installation

1. Download the appropriate binary for your platform from [Releases](https://github.com/ConnrCodes/RGB_TO_HA/releases)
2. Copy the `.xpsm` file to your PixInsight modules directory:
   - **Windows**: `C:\Program Files\PixInsight\bin\modules\`
   - **macOS**: `/Applications/PixInsight/bin/modules/`
   - **Linux**: `/opt/PixInsight/bin/modules/`
3. Restart PixInsight

## Usage

1. Open an RGB image in PixInsight
2. Go to **Process** → **RGB to HA**
3. Adjust parameters as needed:
   - **Conversion Method**: Choose spectral coefficients, adaptive matching, or neural enhancement
   - **Quality Settings**: Adjust noise reduction and sharpening
   - **Color Balance**: Fine-tune the HA color representation
4. Click **Apply** to process the image

## Development

### Building from Source

```bash
# Clone the repository
git clone https://github.com/ConnrCodes/RGB_TO_HA.git
cd RGB_TO_HA

# Build the plugin
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Repository Structure

- `RGBToHAProcess.cpp` - Core processing algorithms
- `RGBToHAInterface.cpp` - GUI interface implementation
- `RGBToHAModule.cpp` - Module registration
- `repository-server.xml` - PixInsight repository manifest
- `CMakeLists.txt` - Build configuration

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Support

For issues and feature requests, please use the [GitHub Issues](https://github.com/ConnrCodes/RGB_TO_HA/issues) page.

---

**Developer**: Connor (@ConnrCodes)  
**Repository**: https://github.com/ConnrCodes/RGB_TO_HA 