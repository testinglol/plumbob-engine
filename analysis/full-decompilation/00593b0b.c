
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00593b0b(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  float *extraout_ECX;
  undefined4 uVar5;
  undefined4 *extraout_EDX;
  int unaff_EBP;
  float10 fVar6;
  
  FUN_00634c24();
  if (ABS(*extraout_ECX - _DAT_00666748) <= _DAT_0067343c) {
LAB_00593c11:
    puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
    uVar5 = *extraout_EDX;
    puVar4[1] = extraout_EDX[1];
    uVar2 = extraout_EDX[2];
    *puVar4 = uVar5;
    puVar4[2] = uVar2;
    uVar5 = extraout_EDX[3];
  }
  else {
    puVar1 = *(undefined4 **)(unaff_EBP + 8);
    cVar3 = FUN_00593c86(puVar1);
    if (cVar3 != '\0') goto LAB_00593c11;
    if (_DAT_0067343c < ABS(*extraout_ECX)) {
      FUN_00593ce0(extraout_EDX,puVar1,0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      puVar4 = (undefined4 *)FUN_00593de8(unaff_EBP + -0x1c,extraout_ECX);
      puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
      uVar5 = *puVar4;
      puVar1[1] = puVar4[1];
      uVar2 = puVar4[3];
      puVar1[2] = puVar4[2];
      *puVar1 = uVar5;
      puVar1[3] = uVar2;
      FUN_005c4890();
      fVar6 = (float10)FUN_005c48d0();
      *(float *)(unaff_EBP + 0xc) = (float)((float10)_DAT_00667280 / fVar6);
      puVar4 = (undefined4 *)FUN_00593c3b(unaff_EBP + -0x1c,unaff_EBP + 0xc);
      *puVar1 = *puVar4;
      puVar1[1] = puVar4[1];
      uVar5 = puVar4[3];
      puVar1[2] = puVar4[2];
      puVar1[3] = uVar5;
      FUN_005c4890();
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005c4890();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005c4890();
      goto LAB_00593c2a;
    }
    puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
    uVar5 = *puVar1;
    puVar4[1] = puVar1[1];
    uVar2 = puVar1[2];
    *puVar4 = uVar5;
    puVar4[2] = uVar2;
    uVar5 = puVar1[3];
  }
  puVar4[3] = uVar5;
LAB_00593c2a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

