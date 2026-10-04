
undefined4 FUN_004671f5(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 *puVar5;
  undefined1 *local_3c;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 0x10);
  if (iVar2 == 1) {
    local_3c = (undefined1 *)0x3;
    puVar5 = local_3c;
  }
  else if (iVar2 == 2) {
    local_3c = (undefined1 *)0x4;
    puVar5 = local_3c;
  }
  else if (iVar2 == 3) {
    local_3c = (undefined1 *)0x1;
    puVar5 = local_3c;
  }
  else {
    puVar5 = (undefined1 *)0x0;
    if (iVar2 == 4) {
      local_3c = (undefined1 *)0x2;
      puVar5 = local_3c;
    }
  }
  puVar3 = *(undefined1 **)(unaff_EBP + 8);
  local_3c = puVar3;
  FUN_004692b6(unaff_EBP + 8);
  local_3c = *(undefined1 **)(unaff_EBP + 8);
  if (local_3c == *(undefined1 **)(extraout_ECX + 0x10)) {
    *(undefined2 *)(unaff_EBP + -0x24) = 0xffff;
    *(undefined2 *)(unaff_EBP + -0x14) = *(undefined2 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -0x38) = *puVar3;
    *(undefined1 *)(unaff_EBP + -0x37) = puVar3[1];
    uVar1 = puVar3[2];
    *(undefined1 **)(unaff_EBP + -0x10) = puVar5;
    *(undefined1 *)(unaff_EBP + -0x36) = uVar1;
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    local_3c = (undefined1 *)(unaff_EBP + -0x38);
    FUN_004691c0(unaff_EBP + -0x24);
  }
  else {
    if (*(short *)(local_3c + 0x14) == *(short *)(unaff_EBP + 0xc)) {
      *(undefined1 ***)(unaff_EBP + 0xc) = &local_3c;
      FUN_00468b7a();
      uVar4 = 0;
      goto LAB_004672bf;
    }
    uVar4 = *(undefined4 *)(unaff_EBP + 0x10);
    *(short *)(local_3c + 0x1c) = *(short *)(unaff_EBP + 0xc);
    *(undefined4 *)(local_3c + 0x20) = uVar4;
  }
  uVar4 = 1;
LAB_004672bf:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

