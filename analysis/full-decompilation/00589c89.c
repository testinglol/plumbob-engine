
void __fastcall FUN_00589c89(int *param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = param_1[0x4e];
  iVar1 = *(int *)(iVar4 + 0xf8);
  param_1[0x20] = (int)(float)iVar1;
  iVar2 = *(int *)(iVar4 + 0xf4);
  sVar3 = *(short *)(iVar4 + 0x4c);
  param_1[0x21] = (int)(float)iVar2;
  param_1[0x72] = (int)(float)iVar2;
  DAT_006f6d14 = 6;
  DAT_006f6d18 = 6;
  param_1[0x22] = (int)(float)(int)sVar3;
  param_1[0x23] = 0;
  param_1[0x73] = (int)(float)(int)sVar3;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x71] = (int)(float)iVar1;
  (**(code **)(*param_1 + 0x90))(0x3f800000);
  param_1[0x62] = 1;
  param_1[0x7b] = 0;
  param_1[0x60] = 0;
  param_1[99] = 0;
  param_1[100] = 3;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  return;
}

