using System;
using Silk.NET.GLFW;

namespace Enigma.Glfw
{
    public struct OpenGLInfo
    {
        public ClientApi Api;
        public OpenGlProfile Profile;
        public int MajorVersion;
        public int MinorVersion;

        public OpenGLInfo(OpenGlProfile profile, int majorVersion, int minorVersion, ClientApi api)
        {
            Profile = profile;
            MajorVersion = majorVersion;
            MinorVersion = minorVersion;
            Api = api;
        }

        public override bool Equals(object obj)
        {
            return obj is OpenGLInfo other &&
                   Profile == other.Profile &&
                   MajorVersion == other.MajorVersion &&
                   MinorVersion == other.MinorVersion &&
                   Api == other.Api;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Profile, MajorVersion, MinorVersion, Api);
        }

        public void Deconstruct(out OpenGlProfile profile, out int majorVersion, out int minorVersion, out ClientApi api)
        {
            profile = Profile;
            majorVersion = MajorVersion;
            minorVersion = MinorVersion;
            api = Api;
        }

        public static implicit operator (OpenGlProfile profile, int majorVersion, int minorVersion, ClientApi api)(OpenGLInfo value)
        {
            return (value.Profile, value.MajorVersion, value.MinorVersion, value.Api);
        }

        public static implicit operator OpenGLInfo((OpenGlProfile profile, int majorVersion, int minorVersion, ClientApi api) value)
        {
            return new OpenGLInfo(value.profile, value.majorVersion, value.minorVersion, value.api);
        }

        public static bool operator ==(OpenGLInfo left, OpenGLInfo right)
        {
            return left.Equals(right);
        }

        public static bool operator !=(OpenGLInfo left, OpenGLInfo right)
        {
            return !left.Equals(right);
        }
    }
}
