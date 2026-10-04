
void __fastcall FUN_00459e8f(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x118);
  if (*(short *)(iVar1 + 0x66) == 0) {
    if ((*(short *)(param_1 + 0x600) == 0) || (0x11 < *(short *)(param_1 + 0x600))) {
      uVar3 = 0x1f5;
    }
    else {
      uVar3 = 0x1f7;
    }
    uVar2 = FUN_00401f73(uVar3);
  }
  else {
    uVar3 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x66));
    uVar2 = FUN_00401f6f(uVar3);
  }
  FUN_0042132a(uVar2,uVar3);
  return;
}

