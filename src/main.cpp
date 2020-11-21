#include <stdio.h>
#include "./modules/audio_device/include/audio_device.h"
#if 0
#include "api/audio_codecs/builtin_audio_decoder_factory.h"
#include "api/audio_codecs/builtin_audio_encoder_factory.h"
#include "api/rtp_parameters.h"
#include "api/scoped_refptr.h"
#include "call/call.h"
#include "logging/rtc_event_log/rtc_event_log.h"
#include "media/base/fake_media_engine.h"
#include "media/base/fake_network_interface.h"
#include "media/base/fake_rtp.h"
#include "media/base/media_constants.h"
#include "media/engine/webrtc_voice_engine.h"
#include "modules/audio_processing/include/mock_audio_processing.h"
#include "pc/channel.h"
#include "rtc_base/arraysize.h"
#include "rtc_base/byte_order.h"
#include "rtc_base/numerics/safe_conversions.h"
#include "test/field_trial.h"
#include "test/gtest.h"
#include "test/mock_audio_decoder_factory.h"
#include "test/mock_audio_encoder_factory.h"
#endif
#include "api/task_queue/default_task_queue_factory.h"
#include "./api/audio/audio_frame.h"
#include "./modules/audio_device/linux/audio_device_alsa_linux.h"
#include "./modules/audio_device/audio_device_impl.h"

using namespace webrtc;

//open audio device
// record audio
// play audio  
//close audio device  
 std::unique_ptr<TaskQueueFactory> task_queue_factory_;
 AudioParameters playout_parameters_;
  AudioParameters record_parameters_;
 rtc::scoped_refptr<AudioDeviceModule> audio_device_;

rtc::scoped_refptr<AudioDeviceModule> CreateAudioDevice(
	AudioDeviceModule::AudioLayer audio_layer) {
rtc::scoped_refptr<AudioDeviceModule> module(
	AudioDeviceModule::Create(audio_layer, task_queue_factory_.get()));
return module;
}

rtc::scoped_refptr<AudioDeviceModule> audio_device()  {
	return audio_device_;
}

int main(){
	printf("hello  webrtc  %d\n",AudioDeviceModule::kLinuxAlsaAudio);
	//class AudioDeviceModule a = AudioDeviceModule::Create();
 	 //class AudioDeviceModule imp =  AudioDeviceModule::CreateForTest(AudioDeviceModule::kLinuxAlsaAudio,nullptr);
 
	class AudioFrame *af = new AudioFrame();
	af->ResetWithoutMuting();
	

	class AudioDeviceLinuxALSA *audioDev = new AudioDeviceLinuxALSA();
	audioDev->Init();
	printf("main  RecordingDevices \n");
	audioDev->RecordingDevices();
	bool available ;
	audioDev->RecordingIsAvailable(available);
	printf("available = %d  %d \n",available,false);

	audioDev->StereoRecordingIsAvailable(available);
	printf("Stereo  available = %d  %d \n",available,false);

	task_queue_factory_ =  CreateDefaultTaskQueueFactory();

	
	 audio_device_ = CreateAudioDevice(AudioDeviceModule::kPlatformDefaultAudio);
	if(audio_device_.get() == nullptr){
		printf("audio_device_ nullptr \n");
	}
    if(0 != audio_device_->Init()){
		printf("audio_device_ init failed \n");
	}


	return 0;
}
