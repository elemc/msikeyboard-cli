project('msikeyboard_cli',
        'cpp',
        version : '0.1',
        meson_version : '>= 0.47.0',
        default_options : [
            'warning_level=1',
            'cpp_std=c++14'
        ]
)

libmsikeyboard_dep = dependency(
    'msikeyboard',
    required: true,
)
boost_dep = dependency(
    'boost',
    required: true,
    modules: [
        'program_options',
    ]
)

bin = executable(
    'msikeyboard_cli', sources: [
        'main.cpp',
        'MSIKeyboard.cpp',
        'MSIKeyboard.h',
        'Region.cpp',
        'Region.h',
    ],
    dependencies: [
        libmsikeyboard_dep,
        boost_dep
    ],
    install: true
)