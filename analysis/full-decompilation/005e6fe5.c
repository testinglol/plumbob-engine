
void Catch_005e6fe5(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x1c);
  puVar2 = puVar1;
  if (puVar1 != *(undefined4 **)(unaff_EBP + -0x18)) {
    do {
      (**(code **)*puVar2)(0);
      puVar2 = puVar2 + 0xb;
    } while (puVar2 != *(undefined4 **)(unaff_EBP + -0x18));
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_0040189d(puVar1,*(int *)(unaff_EBP + -0x14) * 0x2c);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

