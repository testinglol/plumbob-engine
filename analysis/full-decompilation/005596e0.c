
void __fastcall FUN_005596e0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  uVar2 = FUN_005e74ca(3);
  FUN_005dde6d(uVar2);
  piVar3 = (int *)(param_1 + 0x154);
  iVar4 = 0xe;
  do {
    piVar1 = (int *)*piVar3;
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_004f5aa0(1);
  return;
}

