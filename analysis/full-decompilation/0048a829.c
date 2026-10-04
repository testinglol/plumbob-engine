
void FUN_0048a829(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  int unaff_EBP;
  bool bVar5;
  undefined4 local_40;
  
  FUN_00634c24();
  local_40 = 0x48a83c;
  uVar1 = FUN_00492b26();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  *(char *)(unaff_EBP + 10) = (char)uVar1;
  iVar2 = **(int **)(unaff_EBP + 8);
  cVar4 = (char)((*(int **)(unaff_EBP + 8))[1] >> 4);
  *(char *)(unaff_EBP + 8) = cVar4;
  uVar3 = (undefined1)(iVar2 >> 4);
  *(undefined1 *)(unaff_EBP + 9) = uVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = &local_40;
  local_40._3_1_ = (char)(iVar2 >> 0x1c);
  local_40 = CONCAT22(CONCAT11(local_40._3_1_,(char)uVar1),CONCAT11(uVar3,cVar4));
  FUN_00467768(unaff_EBP + -0x44);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  bVar5 = ((byte)*(undefined4 *)(unaff_EBP + -0x44) & 1) != 1;
  if (((byte)*(undefined4 *)(unaff_EBP + -0x44) & 2) == 2) {
    if (bVar5) {
      **(undefined4 **)(unaff_EBP + 0xc) = 2;
      goto LAB_0048a8fa;
    }
    local_40 = *(undefined4 *)(unaff_EBP + -0x10);
    *(int *)(unaff_EBP + -0x18) = (int)cVar4;
    *(int *)(unaff_EBP + -0x14) = (int)*(char *)(unaff_EBP + 9);
    uVar1 = FUN_004a6a71(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + 8) = uVar1;
    iVar2 = (*(short *)(unaff_EBP + 10) < *(short *)(*(int *)(unaff_EBP + 0x10) + 2)) + 1;
  }
  else {
    if (!bVar5) {
      **(undefined4 **)(unaff_EBP + 0xc) = 1;
      goto LAB_0048a8fa;
    }
    iVar2 = (-(uint)(((byte)*(undefined4 *)(unaff_EBP + -0x44) & 0x10) != 0x10) & 0xfffffff0) + 0x10
    ;
  }
  **(int **)(unaff_EBP + 0xc) = iVar2;
LAB_0048a8fa:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

