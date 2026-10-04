
uint FUN_0049177e(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar2 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 8) = *puVar2;
  uVar1 = puVar2[2];
  *(undefined1 *)(unaff_EBP + 9) = puVar2[1];
  *(undefined1 *)(unaff_EBP + 10) = uVar1;
  iVar3 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(-*(int *)(iVar3 + 0x84) & 3);
  uVar4 = FUN_0043f371(*DAT_006e486c,unaff_EBP + 8,0);
  do {
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar4 = uVar4 & 0xffffff00;
LAB_004917f3:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar4;
    }
    if ((*(byte *)(*(int *)(unaff_EBP + -0x14) + 0x9f) & 1) == 0) {
      uVar4 = CONCAT31((int3)((uint)*(int *)(unaff_EBP + -0x14) >> 8),1);
      goto LAB_004917f3;
    }
    uVar4 = FUN_0043f3b9();
  } while( true );
}

