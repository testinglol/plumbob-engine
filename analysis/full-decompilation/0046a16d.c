
undefined4 __fastcall FUN_0046a16d(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  FUN_004071be(param_1[0xc],param_1[0xd]);
  FUN_004071be(param_1[0xf],param_1[0x10]);
  param_1[0x12] = 0;
  piVar1 = param_1 + 0x12;
  param_1[0x13] = 1;
  iVar3 = FUN_00469872(0);
  iVar2 = *param_1;
  *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar2 + 0x10);
  fVar4 = (float10)FUN_0046989d(*piVar1);
  *(undefined4 *)(iVar3 + 0x1c) = 0xffffffff;
  *(float *)(iVar3 + 0x28) = (float)fVar4;
  *(undefined4 *)(iVar3 + 0x24) = 0;
  *(float *)(iVar3 + 0x20) = (float)fVar4;
  param_1[0x14] = *piVar1;
  FUN_0040555d(piVar1);
  return 1;
}

