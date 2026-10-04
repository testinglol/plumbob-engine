
void __fastcall FUN_004cb3c2(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((char)param_1[0x3c] != '\0') {
    if ((uint)param_1[0x3b] <= DAT_006e5490) {
      FUN_004cb21d(param_1[0x3f],param_1[0x40]);
      *(undefined1 *)(param_1 + 0x3c) = 0;
      (**(code **)(*param_1 + 0x90))(0x400,1);
      return;
    }
    FUN_00473496(DAT_006e5490);
    uVar1 = __ftol();
    uVar2 = __ftol(uVar1);
    FUN_004cb21d(uVar2,uVar1);
    FUN_005db0b7();
  }
  return;
}

