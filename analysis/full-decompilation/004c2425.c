
void __fastcall FUN_004c2425(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(DAT_006e486c + 4);
  uVar2 = (**(code **)(*piVar1 + 0x18))();
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  uVar2 = (**(code **)(*piVar1 + 0x14))();
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  *(undefined4 *)(param_1 + 0x18) = 10000;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0x140;
  *(undefined4 *)(param_1 + 0x28) = 0xf0;
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 0x2c) = 0x40000000;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = 0x40400000;
  }
  uVar2 = FUN_004c2743(*(undefined4 *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  FUN_0046f8cb(s_SimsWebCam_jpg_006c75c8);
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  FUN_004c2896();
  return;
}

