
void __fastcall FUN_004782a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar2);
  }
  iVar2 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (iVar2 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar2);
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (iVar2 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar2);
  }
  iVar2 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (iVar2 != 0) {
    thunk_FUN_00431242();
    FUN_006321f0(iVar2);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(int *)(param_1 + 0x60) != 0) {
    FUN_0046176c();
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  if (*(int *)(param_1 + 100) != 0) {
    FUN_0046176c();
    *(undefined4 *)(param_1 + 100) = 0;
  }
  piVar3 = (int *)(param_1 + 0x44);
  iVar2 = 2;
  do {
    iVar1 = piVar3[-8];
    if (iVar1 != 0) {
      thunk_FUN_00431242();
      FUN_006321f0(iVar1);
    }
    piVar3[-8] = 0;
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      thunk_FUN_00431242();
      FUN_006321f0(iVar1);
    }
    *piVar3 = 0;
    iVar1 = piVar3[-2];
    if (iVar1 != 0) {
      thunk_FUN_00431242();
      FUN_006321f0(iVar1);
    }
    piVar3[-2] = 0;
    iVar1 = piVar3[-6];
    if (iVar1 != 0) {
      thunk_FUN_00431242();
      FUN_006321f0(iVar1);
    }
    piVar3[-6] = 0;
    iVar1 = piVar3[-4];
    if (iVar1 != 0) {
      thunk_FUN_00431242();
      FUN_006321f0(iVar1);
    }
    piVar3[-4] = 0;
    iVar1 = piVar3[2];
    if (iVar1 != 0) {
      thunk_FUN_00431242();
      FUN_006321f0(iVar1);
    }
    piVar3[2] = 0;
    iVar1 = piVar3[9];
    if (iVar1 != 0) {
      thunk_FUN_0047c52f();
      FUN_006321f0(iVar1);
    }
    piVar3[9] = 0;
    if ((undefined4 *)piVar3[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar3[5])(1);
    }
    piVar3[5] = 0;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

