
int FUN_005d29f9(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  **(undefined4 **)(unaff_EBP + 0xc) = 0;
  pvVar2 = operator_new(0x11c);
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005d4807(*(undefined4 *)(extraout_ECX + 0xc),*(undefined4 *)(unaff_EBP + 8))
    ;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + -0x10) = piVar3;
  if (piVar3 == (int *)0x0) {
    iVar4 = -0x64f4ffff;
  }
  else {
    (**(code **)(*piVar3 + 4))();
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar4 = FUN_005d2cdc(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x14);
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      iVar4 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 **)(unaff_EBP + -0x14),&DAT_00677268,unaff_EBP + 8);
      if (-1 < iVar4) {
        *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4) = *(undefined4 *)(unaff_EBP + -0x14);
        *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8) = *(undefined4 *)(unaff_EBP + 8);
        _memset((void *)(unaff_EBP + -0x94),0,0x7c);
        *(undefined4 *)(unaff_EBP + -0x94) = 0x7c;
        FUN_005d2b63(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x94);
        *(bool *)(*(int *)(unaff_EBP + -0x10) + 0x119) = *(int *)(unaff_EBP + -0x30) != 0;
        *(byte *)(*(int *)(unaff_EBP + -0x10) + 0x118) =
             (byte)(*(uint *)(unaff_EBP + -0x2c) >> 0xe) & 1;
        puVar1 = *(undefined4 **)(*(int *)(extraout_ECX + 0xc) + 0x38);
        iVar4 = (**(code **)*puVar1)(puVar1,&DAT_00677288,unaff_EBP + -0x18);
        if (-1 < iVar4) {
          iVar4 = (**(code **)(**(int **)(unaff_EBP + 8) + 0xc))
                            (*(int **)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                             *(int *)(unaff_EBP + -0x10) + 0xc);
          (**(code **)(**(int **)(unaff_EBP + -0x18) + 8))(*(int **)(unaff_EBP + -0x18));
          if (iVar4 == 0) {
            FUN_005d2dab(unaff_EBP + -0x10);
            **(undefined4 **)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -0x10);
            goto LAB_005d2b52;
          }
        }
      }
    }
    if (*(undefined4 **)(unaff_EBP + -0x10) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(unaff_EBP + -0x10))(1);
    }
  }
LAB_005d2b52:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

