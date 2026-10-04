
uint __fastcall FUN_005fa9f6(int param_1)

{
  if (*(char *)(param_1 + 0x25) != '\0') {
    return (-(uint)(*(int *)(param_1 + 0xbc) != 0) & 0xfffffffe) + 3;
  }
  return (uint)(*(int *)(param_1 + 0x80) != 0);
}

