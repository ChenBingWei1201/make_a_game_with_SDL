# sdl_bgi.spec - tested on Fedora 34

%global debug_package %{nil} 

Summary:       SDL2-based 'GRAPHICS.H' implementation
Name:          SDL_bgi
Version:       2.6.0
Release:       1
License:       ZLib
Group:         Libraries
Source:        %{name}-%{version}.tar.gz
URL:           http://sdl_bgi.sourceforge.net/
BuildRequires: SDL2-devel
Prefix:        %{_prefix}
BuildRoot:     %{_tmppath}/%{name}-%{version}-buildroot

%description
SDL_bgi is a Borland Graphics Interface ('GRAPHICS.H') implementation
based on SDL2. This library strictly emulates BGI functions, making it
possible to compile SDL2 versions of programs written for Turbo
C/Borland C++. ARGB colours, vector fonts, mouse support, and multiple
windows are also implemented; further, native SDL2 functions may be
used in SDL_bgi programs. SDL_bgi also supports Wasm via Emscripten.

%prep
%setup -q -n %{name}-%{version}

%build
cd src
make

%install
rm -rf $RPM_BUILD_ROOT
cd src
mkdir -p $RPM_BUILD_ROOT/%{_libdir}
mkdir -p $RPM_BUILD_ROOT/%{_includedir}
mkdir -p $RPM_BUILD_ROOT/%{_includedir}/SDL2/
mkdir -p $RPM_BUILD_ROOT/%{_docdir}/%{name}/test/assets/
mkdir -p $RPM_BUILD_ROOT/%{_docdir}/%{name}/test/shells/
mkdir -p $RPM_BUILD_ROOT/%{_mandir}/man3/
/usr/bin/install -m 644 graphics.h $RPM_BUILD_ROOT/%{_includedir}
/usr/bin/install -m 644 SDL_bgi.h  $RPM_BUILD_ROOT/%{_includedir}/SDL2/
/usr/bin/install -m 644 lib%{name}.so $RPM_BUILD_ROOT/%{_libdir}
cd ../doc/
/usr/bin/install -m 644 graphics.3.gz  $RPM_BUILD_ROOT/%{_mandir}/man3/
cd ..
/usr/bin/install -m 644 test/*.* $RPM_BUILD_ROOT/%{_docdir}/%{name}/test/
/usr/bin/install -m 644 test/assets/* $RPM_BUILD_ROOT/%{_docdir}/%{name}/test/assets/
/usr/bin/install -m 644 test/shells/* $RPM_BUILD_ROOT/%{_docdir}/%{name}/test/shells/

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(644,root,root,755)
%doc AUTHORS BUGS ChangeLog INSTALL_Emscripten.md
%doc INSTALL_Linux.md INSTALL_Windows.md INSTALL_macOS.md
%doc LICENSE README.md sdl_bgi.spec TODO VERSION
%attr(644,root,root) %{_libdir}/lib%{name}.so
%attr(644,root,root) %{_includedir}/SDL2/SDL_bgi.h
%attr(644,root,root) %{_includedir}/graphics.h
%attr(644,root,root) %{_mandir}/man3/graphics.3.gz
%attr(644,root,root) %{_docdir}/%{name}/test/*


%changelog
* Sat May 28 2022 Guido Gonzato <guido.gonzato at gmail.com>
Improved document section.

* Tue Jan 2 2018 Guido Gonzato <guido.gonzato at gmail.com>
Slightly improved portability.

* Sun Oct 22 2017 Guido Gonzato <guido.gonzato at gmail.com>
Slightly improved portability.

* Thu Nov 6 2014 Guido Gonzato <guido.gonzato at gmail.com>
This is a generic rpm, also buildable on Ubuntu
