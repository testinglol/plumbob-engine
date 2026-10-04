
int FUN_00458058(void)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(short *)(extraout_ECX[0x18] + 0x12) == 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = extraout_ECX[0x22];
    if (iVar1 == 0) {
      pvVar2 = operator_new(0x6c);
      *(void **)(unaff_EBP + -0x10) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar2 == (void *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)FUN_00455e7f();
      }
      iVar1 = extraout_ECX[0x18];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x22] = piVar3;
      (**(code **)(*piVar3 + 4))
                (*extraout_ECX,CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x26)))
      ;
      iVar1 = extraout_ECX[0x22];
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

