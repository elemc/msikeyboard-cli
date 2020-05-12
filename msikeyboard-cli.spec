Name:           msikeyboard-cli
Version:        0.1
Release:        1%{?dist}
Summary:        CLI application for change LED color, intensity and mode on MSI keyboards

License:        GPLv3
URL:            https://elemc.name
Source0:        https://repo.elemc.name/sources/%{name}-%{version}.tar.xz

BuildRequires:  hidapi-devel
BuildRequires:  meson
BuildRequires:  gcc
BuildRequires:  libmsikeyboard-devel

%description
CLI application for change LED color, intensity and modes on MSI keyboards

%package        systemd
Summary:        SystemD files for %{name}
Requires:       %{name}%{?_isa} = %{version}-%{release}

%description    systemd
The %{name}-systemd package contains SystemD unit for
start applications with configuration on system start.

%prep
%autosetup

%build
%meson
%meson_build

%install
rm -rf $RPM_BUILD_ROOT
%meson_install

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%files
%{_bindir}/msikeyboard_cli

%files systemd

%changelog
* Tue May 12 2020 Alexei Panov <me AT elemc DOT name> 0.1-1
- Initial build
