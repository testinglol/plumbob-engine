
int __thiscall FUN_006092f4(int param_1,uint param_2)

{
  int iVar1;
  
  if (((param_2 == 0x5f) || (0xff < param_2)) || ((&DAT_006d98bc)[param_2] == '\0')) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x10) + (int)(char)(&DAT_006d98bc)[param_2];
  }
  return iVar1;
}

