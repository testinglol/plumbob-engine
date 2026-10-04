
int * FUN_00598dab(void)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  pvVar3 = operator_new(0xd4);
  *(void **)(unaff_EBP + -0x18) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_00598f28();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *piVar4 = *piVar4 + 1;
  FUN_005d499c(extraout_ECX + 4);
  iVar6 = *(int *)(extraout_ECX + 0x68);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar5 = iVar6 - *(int *)(extraout_ECX + 100) >> 2;
  *(int *)(unaff_EBP + -0x18) = iVar5;
  iVar6 = extraout_ECX;
  if (0 < iVar5) {
    while( true ) {
      iVar6 = *(int *)(*(int *)(iVar6 + 100) + *(int *)(unaff_EBP + -0x10) * 4);
      pvVar3 = operator_new(0x16c);
      *(void **)(unaff_EBP + -0x1c) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00598953();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00595f2a(iVar6);
      FUN_005d499c(iVar6 + 0x10);
      *(int *)(iVar5 + 0x130) = *(int *)(iVar5 + 0x130) + 1;
      FUN_00595f04(*(undefined4 *)(iVar6 + 0x2c));
      FUN_00598f04(iVar6 + 0x30);
      FUN_0058669c(iVar6 + 0x3c);
      uVar1 = *(undefined4 *)(iVar6 + 0x74);
      *(int *)(iVar5 + 0x130) = *(int *)(iVar5 + 0x130) + 1;
      *(undefined4 *)(iVar5 + 0x74) = uVar1;
      uVar1 = *(undefined4 *)(iVar6 + 0x78);
      *(undefined4 *)(iVar5 + 0x78) = uVar1;
      FUN_00595d81(uVar1);
      *(int *)(iVar5 + 0x130) = *(int *)(iVar5 + 0x130) + 1;
      iVar2 = *(int *)(iVar5 + 0x130);
      *(undefined4 *)(iVar5 + 0x7c) = *(undefined4 *)(iVar6 + 0x7c);
      *(int *)(iVar5 + 0x130) = iVar2 + 1;
      *(undefined4 *)(iVar5 + 0x70) = *(undefined4 *)(iVar6 + 0x70);
      *(int *)(iVar5 + 0x130) = iVar2 + 2;
      *(undefined4 *)(iVar5 + 0x6c) = *(undefined4 *)(iVar6 + 0x6c);
      *(int *)(iVar5 + 0x130) = iVar2 + 3;
      *(undefined1 *)(iVar5 + 300) = *(undefined1 *)(iVar6 + 300);
      FUN_0059903f(iVar5);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      if (*(int *)(unaff_EBP + -0x18) <= *(int *)(unaff_EBP + -0x10)) break;
      iVar6 = *(int *)(unaff_EBP + -0x14);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar4;
}

