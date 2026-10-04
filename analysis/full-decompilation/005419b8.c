
uint FUN_005419b8(void)

{
  char cVar1;
  int unaff_EBP;
  uint uVar2;
  uint uVar3;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  uVar3 = *(uint *)(unaff_EBP + 8);
  do {
    cVar1 = (**(code **)(unaff_EBP + 0x14))(uVar3,unaff_EBP + 0x10);
    if (cVar1 == '\0') {
      do {
        uVar2 = uVar2 - 4;
        cVar1 = (**(code **)(unaff_EBP + 0x14))(unaff_EBP + 0x10,uVar2);
      } while (cVar1 != '\0');
      if (uVar2 <= uVar3) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (*(int *)(unaff_EBP + 0x10) != 0) {
          FUN_0053d900();
        }
        ExceptionList = *(void **)(unaff_EBP + -0xc);
        return uVar3;
      }
      FUN_00541e0a(uVar3,uVar2,0);
    }
    uVar3 = uVar3 + 4;
  } while( true );
}

