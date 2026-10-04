
int FUN_004894b9(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  int unaff_EBP;
  short sVar7;
  
  FUN_00634c24();
  uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
  piVar1 = *(int **)(unaff_EBP + 8);
  *(char *)(unaff_EBP + 10) = (char)uVar5;
  iVar4 = *piVar1;
  cVar2 = (char)(piVar1[1] >> 4);
  *(char *)(unaff_EBP + 8) = cVar2;
  cVar6 = (char)(iVar4 >> 4);
  *(char *)(unaff_EBP + 9) = cVar6;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = (int)cVar2;
  *(int *)(unaff_EBP + -0x10) = (int)cVar6;
  uVar3 = FUN_004a6a71(unaff_EBP + -0x14,uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + 8) = uVar3;
  *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
  iVar4 = FUN_004a697c();
  sVar7 = (short)(iVar4 / 2) + (short)*(undefined4 *)(unaff_EBP + 8);
  uVar5 = FUN_004a6a46(piVar1,uVar5);
  *(undefined4 *)(unaff_EBP + 8) = uVar5;
  if (*(short *)(unaff_EBP + 10) < *(short *)(unaff_EBP + 0xe)) {
    iVar4 = ((sVar7 <= (short)uVar5) - 1 & 0xfffffffe) + 2;
  }
  else {
    iVar4 = ((sVar7 <= (short)uVar5) - 1 & 0xfffffffe) + 3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

