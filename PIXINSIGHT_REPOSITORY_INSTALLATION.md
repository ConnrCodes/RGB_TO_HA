# RGB to HA Conversion - PixInsight Installation

## 🚀 **Installation Instructions**

You must have **PixInsight 1.8.8 or later**. Upgrade as needed from the [PixInsight software distribution page](https://pixinsight.com/).

### **Step 1: Add Repository**
1. In PixInsight, go to **Resources → Updates → Manage Repositories**
2. Click **Add**
3. Enter the repository address (use copy & paste to avoid typos):
   ```
   https://connor.github.io/rgb-to-ha/repository-server.xml
   ```
4. Click **OK**

### **Step 2: Install Extension**
1. Go to **Resources → Updates**
2. You'll see **"RGB to HA Conversion"** listed
3. Click **Install** next to the extension
4. Restart PixInsight when prompted

### **Step 3: Use the Plugin**
1. Open a color image in PixInsight
2. Go to **Process → ColorTransformation → RGB to HA Conversion**
3. Select your preferred conversion method and parameters
4. Apply the process

## 📋 **Repository Details**

- **Repository URL**: `https://connor.github.io/rgb-to-ha/repository-server.xml`
- **Extension Name**: RGB to HA Conversion
- **Version**: 1.0.0
- **Author**: Connor
- **Category**: ColorTransformation

## 🎯 **Supported Platforms**

- ✅ **Windows x64** (Intel/AMD processors)
- ✅ **macOS Intel** (x86_64)
- ✅ **macOS Apple Silicon** (arm64)

## 🔧 **For Developers**

### **GitHub Pages Setup**
1. **Create GitHub repository**: `connor/rgb-to-ha`
2. **Enable GitHub Pages** in repository settings
3. **Upload files** to `docs/` folder:
   ```
   docs/
   ├── repository-server.xml
   └── downloads/
       ├── RGBToHA-pxm.dll      # Windows x64
       ├── RGBToHA-pxm.dylib    # macOS universal
       ├── README.md
       └── LICENSE
   ```

### **Repository Structure**
```
connor.github.io/rgb-to-ha/
├── repository-server.xml        # Repository manifest
└── downloads/
    ├── RGBToHA-pxm.dll         # Windows binary
    ├── RGBToHA-pxm.dylib       # macOS binary
    ├── README.md               # Documentation
    └── LICENSE                 # License file
```

### **Update Process**
1. **Build new version** using build scripts
2. **Upload binaries** to `docs/downloads/`
3. **Update version** in `repository-server.xml`
4. **Commit and push** to GitHub
5. **Users get automatic updates** in PixInsight

## 🎉 **User Experience**

### **One-Click Installation**
- ✅ **Add repository URL** (one-time setup)
- ✅ **Click Install** in Updates tab
- ✅ **Automatic platform detection**
- ✅ **Automatic updates** when new versions released

### **No Manual Downloads**
- ❌ No need to download files manually
- ❌ No need to choose architecture
- ❌ No need to copy files manually
- ❌ No need to manage versions

## 📊 **Features**

### **Conversion Algorithms**
- **Standard RGB to HA**: Basic color space transformation
- **Advanced Spectral**: Multi-band spectral analysis
- **Adaptive Multi-Scale**: Multi-resolution processing
- **Neural Network**: AI-based conversion

### **Enhancement Options**
- **Enhancement Strength**: 0.0 to 1.0
- **Noise Reduction**: Bilateral filtering
- **Contrast Boost**: Histogram stretching
- **HA Wavelength**: 650-670 nm adjustment

## 🔍 **Troubleshooting**

### **Common Issues**

**"Repository not found"**
- Verify URL is correct: `https://connor.github.io/rgb-to-ha/repository-server.xml`
- Check GitHub Pages is enabled
- Ensure repository is public

**"Extension not appearing"**
- Restart PixInsight after adding repository
- Check PixInsight version (1.8.8+ required)
- Verify internet connection

**"Installation failed"**
- Check PixInsight modules directory permissions
- Ensure administrator privileges (Windows) or sudo (macOS)
- Restart PixInsight after installation

### **Getting Help**
- Check GitHub repository: `https://github.com/connor/rgb-to-ha`
- Verify PixInsight installation
- Ensure repository URL is added correctly

## 🎯 **Success Indicators**

After successful installation:
- ✅ **"RGB to HA Conversion"** appears in Updates tab
- ✅ **Install button** is available
- ✅ **Extension downloads** automatically
- ✅ **Process appears** in PixInsight menu after restart

---

**This provides the same professional installation experience as BlurXTerminator!** 