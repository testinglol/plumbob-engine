
void __fastcall FUN_004aadfa(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_005cdf02(*(undefined4 *)(param_1 + 0x170),*(undefined4 *)(param_1 + 0x174));
  *(int *)(param_1 + 0x494) = *(int *)(param_1 + 0x494) + *(int *)(param_1 + 0x170);
  *(int *)(param_1 + 0x498) = *(int *)(param_1 + 0x498) + *(int *)(param_1 + 0x174);
  *(int *)(param_1 + 0x49c) = *(int *)(param_1 + 0x49c) + *(int *)(param_1 + 0x170);
  *(int *)(param_1 + 0x4a0) = *(int *)(param_1 + 0x4a0) + *(int *)(param_1 + 0x174);
  if ((*(int *)(param_1 + 0x4cc) < *(int *)(param_1 + 0x4d4)) &&
     (*(int *)(param_1 + 0x4d0) < *(int *)(param_1 + 0x4d8))) {
    uVar2 = FUN_004b469d();
    uVar1 = DAT_006fe838;
    DAT_006fe838 = DAT_006d6180;
    FUN_005cddcf(uVar2);
    DAT_006fe838 = uVar1;
    *(int *)(param_1 + 0x4cc) = 0;
    *(undefined4 *)(param_1 + 0x4d0) = 0;
    *(undefined4 *)(param_1 + 0x4d4) = 0;
    *(undefined4 *)(param_1 + 0x4d8) = 0;
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_005cf1be(*(undefined4 *)(param_1 + 0x170),*(undefined4 *)(param_1 + 0x174));
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_005caf3d(*(undefined4 *)(param_1 + 0x170),*(undefined4 *)(param_1 + 0x174));
  }
  return;
}

