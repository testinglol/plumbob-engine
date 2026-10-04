
uint __thiscall FUN_005d7a4d(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  size_t _Count;
  char local_104 [256];
  
  if (param_2 == 0x17) {
    uVar1 = param_1[0x3b];
    if ((uVar1 != param_3) || (param_1[0x3c] == 0)) goto LAB_005d7ae0;
    _Count = (*(int *)(uVar1 + 0xe8) - *(int *)(uVar1 + 0xe4)) - 1;
    if (_Count != 0) {
      if (0xff < (int)_Count) {
        _Count = 0xff;
      }
      _strncpy(local_104,*(char **)(uVar1 + 0xe4),_Count);
      local_104[_Count] = '\0';
      uVar1 = FUN_005e64a0(local_104);
      if ((char)uVar1 == '\0') goto LAB_005d7ae0;
    }
  }
  else if (param_2 != 0x18) {
    uVar1 = FUN_005dd97f(param_2,param_3);
    return uVar1;
  }
  uVar1 = (**(code **)(*param_1 + 0x1c4))(0);
LAB_005d7ae0:
  return uVar1 & 0xffffff00;
}

