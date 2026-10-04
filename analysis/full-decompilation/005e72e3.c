
void Catch_005e72e3(void)

{
  int unaff_EBP;
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(unaff_EBP + 0x10); puVar1 != *(undefined4 **)(unaff_EBP + -0x14);
      puVar1 = puVar1 + 0xb) {
    (**(code **)*puVar1)(0);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

