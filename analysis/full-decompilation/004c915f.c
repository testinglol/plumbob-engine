
void FUN_004c915f(void)

{
  short sVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  sVar1 = (**(code **)(*(int *)*extraout_ECX + 0x34))(0x50414c54);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(int *)(unaff_EBP + -0x1c) = (int)sVar1;
  if (0 < sVar1) {
    do {
      iVar4 = 0;
      uVar2 = (**(code **)(*(int *)*extraout_ECX + 0x40))
                        (0x50414c54,*(int *)(unaff_EBP + -0x18) + 1,0);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
      pvVar3 = operator_new(0xe20);
      *(void **)(unaff_EBP + -0x20) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 != (void *)0x0) {
        iVar4 = FUN_004b915a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if ((iVar4 != 0) && (*(int *)(unaff_EBP + -0x14) != 0)) {
        uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
        *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + 1;
        uVar2 = FUN_00420048(uVar2);
        FUN_004b9685(uVar2);
        (**(code **)(*(int *)*extraout_ECX + 0x50))
                  (*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0xe);
        FUN_004b8ddc(iVar4,(int)*(short *)(unaff_EBP + -0xe));
        FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x14));
        FUN_00415317();
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
    } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x1c));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

