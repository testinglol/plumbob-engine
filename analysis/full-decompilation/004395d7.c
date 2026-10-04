
uint FUN_004395d7(void)

{
  char cVar1;
  int unaff_EBP;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = *(uint *)(unaff_EBP + 0xc);
  uVar2 = *(uint *)(unaff_EBP + 8);
  do {
    cVar1 = (**(code **)(unaff_EBP + 0x20))(uVar2,unaff_EBP + 0x10);
    if (cVar1 == '\0') {
      do {
        uVar3 = uVar3 - 0x10;
        cVar1 = (**(code **)(unaff_EBP + 0x20))(unaff_EBP + 0x10,uVar3);
      } while (cVar1 != '\0');
      if (uVar3 <= uVar2) {
        *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
        return uVar2;
      }
      FUN_00439823(uVar2,uVar3,0);
    }
    uVar2 = uVar2 + 0x10;
  } while( true );
}

