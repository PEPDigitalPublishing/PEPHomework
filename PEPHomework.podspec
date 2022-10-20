
Pod::Spec.new do |s|

    s.name            = 'PEPHomework'

    s.version         = '1.0.0'

    s.summary         = 'PEP H5作业模块'

    s.license         = 'MIT'

    s.homepage        = 'https://github.com/PEPDigitalPublishing/PEPHomework.git'

    s.source           = { :git => 'https://github.com/PEPDigitalPublishing/PEPHomework.git', :tag => s.version.to_s }

    s.author          = { '李沛卓' => 'lipz@pep.com.cn' }

    s.platform        = :ios, '11.0'

    s.source_files    = 'HomeworkSample/HomeworkSample/PEPHomework/*.{h,m}'

    s.frameworks      = 'Foundation', 'UIKit', 'WebKit'

end
