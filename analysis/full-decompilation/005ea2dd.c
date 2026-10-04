
void __fastcall FUN_005ea2dd(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x90))(0x100000,1);
    if (param_1[0x39] == 0) {
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      iVar3 = (**(code **)(*piVar2 + 0x10))(1,10,0,0);
      param_1[0x39] = iVar3;
      *(undefined1 *)(param_1 + 0x3a) = 1;
    }
    if (param_1[0x36] == 0) {
      iVar3 = FUN_005dd5e1(0xb9,0xb9,0xd0);
      param_1[0x36] = iVar3;
    }
    if (param_1[0x37] == 0) {
      iVar3 = FUN_005dd5e1(0,0xff,0xff);
      param_1[0x37] = iVar3;
    }
    if (param_1[0x38] == 0) {
      iVar3 = FUN_005dd5e1(0xff,0xff,0xff);
      param_1[0x38] = iVar3;
    }
    if (param_1[0x19] == 0) {
      iVar3 = FUN_005dd5e1(0x76,0x76,0x76);
      param_1[0x19] = iVar3;
    }
    if ((param_1[0x3b] == 0) && ((char)param_1[0x3c] == '\0')) {
      piVar2 = (int *)FUN_005e7743();
      iVar3 = (**(code **)(*piVar2 + 0x10))(0xf);
      param_1[0x3b] = iVar3;
      FUN_005e357a();
      *(undefined1 *)(param_1 + 0x3c) = 0;
    }
  }
  FUN_005dbf32();
  return;
}

