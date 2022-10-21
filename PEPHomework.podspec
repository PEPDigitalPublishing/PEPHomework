
Pod::Spec.new do |s|

    s.name            = 'PEPHomework'

    s.version         = '1.0.3'

    s.summary         = 'PEP H5作业模块'

    s.license         = 'MIT'

    s.homepage        = 'https://github.com/PEPDigitalPublishing/PEPHomework.git'

    s.source           = { :git => 'https://github.com/PEPDigitalPublishing/PEPHomework.git'}

    s.author          = { '李沛卓' => 'lipz@pep.com.cn' }

    s.platform        = :ios, '11.0'

    s.vendored_frameworks = 'PEPHomework.framework'

    s.frameworks      = 'Foundation', 'UIKit', 'WebKit'

end
