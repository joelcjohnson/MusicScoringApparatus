src = ['gpio_input.cpp', 
    'gpio_output.cpp', 
    'mainwindow.cpp', 
    'sequencer.cpp', 
    'writefile.cpp'
    ]

qt_src = ['mainwindow.cpp', 
          'writefile.cpp'
        ]

qt5 = import('qt5')
qt5_deps = dependency('qt5', modules: ['Core', 'Gui'])

qtprocessed = qt5.preprocess(ui_files: 'mainwindow.ui',
                             moc_sources: qt_src,
                             include_directories: incdir)

executable('Music Scorer', 'main.cpp', sources : src, 
        include_directories: incdir,
        dependency: qt5_deps)
