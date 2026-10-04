
undefined4 FUN_0048941c(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar5 = *(undefined1 **)(unaff_EBP + 8);
  uVar1 = *puVar5;
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  *(undefined1 *)(unaff_EBP + -0x10) = uVar1;
  *(undefined1 *)(unaff_EBP + -0xf) = uVar2;
  *(undefined1 *)(unaff_EBP + -0xe) = uVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + 8) = uVar1;
  *(undefined1 *)(unaff_EBP + 9) = uVar2;
  *(undefined1 *)(unaff_EBP + 10) = uVar3;
  iVar6 = DAT_006e54d8;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00434ffd(-*(int *)(iVar6 + 0x84) & 3);
  FUN_0043f371(*DAT_006e486c,unaff_EBP + 8,0);
  do {
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar7 = 1;
LAB_004894ac:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar7;
    }
    uVar4 = *(ushort *)(*(int *)(unaff_EBP + -0x18) + 0x9e);
    if (((uVar4 & 2) == 0) || (('\x01' < (char)puVar5[2] && ((uVar4 & 0x200) == 0)))) {
      uVar7 = 0;
      goto LAB_004894ac;
    }
    FUN_0043f3b9();
  } while( true );
}

