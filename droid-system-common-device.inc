%define __find_provides %{nil}
%define __find_requires %{nil}
%define __strip /bin/true
%define __provides_exclude_from ^/system/.*$
%define __requires_exclude ^.*$
%global debug_package %{nil}

Name:          droid-system-%{habuild_device}-%{device}
# This package bundles system+vendor, remove old vendor package:
Provides:      droid-system-vendor-%{habuild_device}-%{device}
Conflicts:     droid-system-vendor-%{habuild_device}-%{device}
Obsoletes:     droid-system-vendor-%{habuild_device}-%{device}
Summary:       Built certain sources trees such as /system for Droid HAL adaptations
Version:       0.0.1
Release:       1
License:       %{system_license}
Requires:      droid-system-%{habuild_device}
Source0:       %{name}-%{version}.tgz
Source1:       droid-system-%{habuild_device}-rpmlintrc
URL:           https://github.com/mer-hybris/droid-system-sony-template

%description
%{summary}

%prep
%setup -q -n %{name}-%{version}

# This section is empty on purpose
%build

%install
rm -rf $RPM_BUILD_ROOT tmp
mkdir -p $RPM_BUILD_ROOT/system/etc
cp %{device}/system/build.prop $RPM_BUILD_ROOT/system/build.prop
cp %{device}/system/etc/prop.default $RPM_BUILD_ROOT/system/etc/prop.default
mkdir -p $RPM_BUILD_ROOT/vendor/etc/vintf
cp %{device}/vendor/build.prop $RPM_BUILD_ROOT/vendor/build.prop
cp %{device}/vendor/etc/vintf/manifest.xml $RPM_BUILD_ROOT/vendor/etc/vintf/manifest.xml

mkdir tmp
touch tmp/extra_files
if [ -f %{device}/vendor/odm/etc/build.prop ]; then
    mkdir -p $RPM_BUILD_ROOT/vendor/odm/etc
    cp %{device}/vendor/odm/etc/build.prop $RPM_BUILD_ROOT/vendor/odm/etc/build.prop
    echo "/vendor/odm/etc/build.prop" >> tmp/extra_files
fi

%files -f tmp/extra_files
%defattr(-,root,root,-)
/system/build.prop
/system/etc/prop.default
/vendor/build.prop
/vendor/etc/vintf/manifest.xml
