namespace System
{
    public static class EnumExtensions
    {
        public static RT CheckFlags<T, RT>(this T flag, params (T, RT)[] values) where T : Enum
        {
            foreach ((T, RT) value in values)
            {
                if (flag.HasFlag(value.Item1)) 
                    return value.Item2;
            }
            throw new NotImplementedException();
        }

        public static RT CheckFlags<T, RT>(this T flag, params (T, Func<RT>)[] values) where T : Enum
        {
            foreach ((T, Func<RT>) value in values)
            {
                if (flag.HasFlag(value.Item1)) 
                    return value.Item2.Invoke();
            }
            throw new NotImplementedException();
        }
    }
}
