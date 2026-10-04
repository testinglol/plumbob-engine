using System;
using FSO.Common.Audio;
using Microsoft.Xna.Framework.Audio;

namespace FSO.HIT
{
    public interface IHITVoice : ISFXInstanceLike
    {
        bool IsDisposed { get; }
        Model.HITVolumeGroup Group { get; set; }
        int SourceID { get; set; }
        bool Spatial { get; set; }
        bool Zoom { get; set; }
        void Apply3D(AudioListener listener, AudioEmitter emitter);
    }

    public sealed class HITAudioClip
    {
        public string Name { get; }
        public float Duration { get; }
        private readonly Func<IHITVoice> create;

        public HITAudioClip(string name, float duration, Func<IHITVoice> create)
        {
            Name = name;
            Duration = duration;
            this.create = create;
        }

        public IHITVoice CreateInstance() => create();

        public static HITAudioClip FromSoundEffect(SoundEffect effect) => effect == null ? null :
            new HITAudioClip(effect.Name, (float)effect.Duration.TotalSeconds, () => new XNAVoice(effect.CreateInstance()));

        private sealed class XNAVoice : IHITVoice
        {
            private readonly SoundEffectInstance instance;
            public XNAVoice(SoundEffectInstance instance) { this.instance = instance; }
            public float Volume { get => instance.Volume; set => instance.Volume = value; }
            public float Pan { get => instance.Pan; set => instance.Pan = value; }
            public bool IsLooped { get => instance.IsLooped; set => instance.IsLooped = value; }
            public bool IsDisposed => instance.IsDisposed;
            public Model.HITVolumeGroup Group { get; set; }
            public int SourceID { get; set; }
            public bool Spatial { get; set; }
            public bool Zoom { get; set; }
            public SoundState State => instance.State;
            public void Play() => instance.Play();
            public void Stop() => instance.Stop();
            public void Pause() => instance.Pause();
            public void Resume() => instance.Resume();
            public void Dispose() => instance.Dispose();
            public void Apply3D(AudioListener listener, AudioEmitter emitter) => instance.Apply3D(listener, emitter);
        }
    }
}
