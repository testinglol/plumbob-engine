
void __fastcall FUN_00521664(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x198) != -1) && (*(int *)(param_1 + 0x19c) != 0)) {
    iVar1 = FUN_004e9744(*(int *)(param_1 + 0x198));
    if ((iVar1 == 0) || (*(short *)(iVar1 + 0x60e) < 2)) {
      uVar2 = *(undefined4 *)(param_1 + 0x1a0);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x1a4);
    }
    FUN_005d4bbf(uVar2);
  }
  return;
}

