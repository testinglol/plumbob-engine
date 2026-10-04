
uint FUN_006058b3(void)

{
  undefined4 *_Dst;
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  _Dst = *(undefined4 **)(unaff_EBP + 0xc);
  _memset(_Dst,0,0x20);
  *_Dst = 0x20;
  piVar1 = *(int **)(unaff_EBP + 8);
  *piVar1 = 0;
  piVar1[1] = 0;
  iVar2 = (**(code **)(**(int **)(extraout_ECX + 4) + 0x54))(*(int **)(extraout_ECX + 4),_Dst);
  if (iVar2 != 0) {
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
LAB_0060591a:
    uVar3 = uVar3 & 0xffffff00;
    goto LAB_006059e3;
  }
  *(undefined4 *)(extraout_ECX + 0x180) = _Dst[3];
  uVar3 = _Dst[3];
  iVar2 = 4;
  if (uVar3 == 4) {
    iVar4 = 2;
LAB_006059dc:
    *piVar1 = iVar4;
    piVar1[1] = iVar2;
  }
  else {
    iVar2 = 8;
    if (uVar3 == 8) {
      iVar4 = 3;
      goto LAB_006059dc;
    }
    if (uVar3 != 0x10) {
      if ((uVar3 != 0x18) && (uVar3 != 0x20)) {
        *(undefined4 *)(extraout_ECX + 0x180) = 0;
        goto LAB_0060591a;
      }
      iVar2 = 0;
      iVar4 = 9;
      goto LAB_006059dc;
    }
    iVar4 = _Dst[4];
    if (((iVar4 == 0x7c00) && (_Dst[5] == 0x3e0)) && (_Dst[6] == 0x1f)) {
      iVar4 = 5;
LAB_0060597d:
      iVar2 = 0x10;
      goto LAB_006059dc;
    }
    if (((iVar4 == 0xf800) && (_Dst[5] == 0x7e0)) && (_Dst[6] == 0x1f)) {
      iVar4 = 7;
      goto LAB_0060597d;
    }
    if (((iVar4 == 0xfc00) && (_Dst[5] == 0x3e0)) && (_Dst[6] == 0x1f)) {
      iVar4 = 6;
      goto LAB_0060597d;
    }
    if (((iVar4 == 0xf800) && (_Dst[5] == 0x7c0)) && (_Dst[6] == 0x3f)) {
      iVar4 = 8;
      goto LAB_0060597d;
    }
    *(undefined4 *)(extraout_ECX + 0x180) = 0;
  }
  uVar3 = CONCAT31((int3)((uint)iVar4 >> 8),1);
LAB_006059e3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

