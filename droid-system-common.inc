%define dsd_path ./

Requires(post): coreutils
Requires(post): libcap

# This package bundles system+vendor, remove old vendor package:
Provides:  droid-system-vendor-%{rpm_device}
Conflicts: droid-system-vendor-%{rpm_device}
Obsoletes: droid-system-vendor-%{rpm_device}
