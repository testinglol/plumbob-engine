
void __fastcall FUN_004cf579(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  if (*(int *)(param_1 + 0xa4) == 0) {
    *(undefined4 *)(param_1 + 0xe0) = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xa0);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0xa8);
      iVar2 = *(int *)(param_1 + 0xac);
    }
    else if (iVar1 == 1) {
      iVar1 = *(int *)(param_1 + 0xb0);
      iVar2 = *(int *)(param_1 + 0xb4);
    }
    else if (iVar1 == 2) {
      iVar1 = *(int *)(param_1 + 0xb8);
      iVar2 = *(int *)(param_1 + 0xbc);
    }
    else if (iVar1 == 3) {
      iVar1 = *(int *)(param_1 + 0xc0);
      iVar2 = *(int *)(param_1 + 0xc4);
    }
    else if (iVar1 == 4) {
      iVar1 = *(int *)(param_1 + 200);
      iVar2 = *(int *)(param_1 + 0xcc);
    }
    else if (iVar1 == 5) {
      iVar1 = *(int *)(param_1 + 0xd0);
      iVar2 = *(int *)(param_1 + 0xd4);
    }
    else {
      if (iVar1 != 6) goto LAB_004cf626;
      iVar1 = *(int *)(param_1 + 0xd8);
      iVar2 = *(int *)(param_1 + 0xdc);
    }
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xec + (iVar2 + iVar1 * 8) * 4);
  }
LAB_004cf626:
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 4;
  return;
}

