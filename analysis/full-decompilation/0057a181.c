
void FUN_0057a181(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  size_t sVar6;
  char *extraout_ECX;
  int *piVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((char)DAT_006fe8bc[0x4f] == '\0') {
    extraout_ECX[0x14] = '\0';
  }
  if ((extraout_ECX[0x14] != '\0') && (*extraout_ECX == '\0')) {
    piVar7 = (int *)0x0;
    uVar3 = (**(code **)(*DAT_006fe8bc + 0x14))
                      (0,&cITSSndSys::RTTI_Type_Descriptor,&cTSSndSys::RTTI_Type_Descriptor,0);
    puVar4 = (undefined4 *)FUN_006359f2(uVar3);
    *(undefined4 **)(extraout_ECX + 4) = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)();
    }
    if (((*extraout_ECX == '\0') && (*(int *)(unaff_EBP + 8) != 0)) &&
       (*(int *)(extraout_ECX + 4) != 0)) {
      *extraout_ECX = '\x01';
      extraout_ECX[0x10] = '\0';
      extraout_ECX[0x11] = '\0';
      extraout_ECX[0x12] = '\0';
      extraout_ECX[0x13] = '\0';
      pvVar5 = operator_new(0x118);
      *(void **)(unaff_EBP + 8) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar5 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_00571424();
      }
      uVar1 = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(extraout_ECX + 0xc) = uVar3;
      FUN_005d4956(uVar1);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d4956(*(undefined4 *)(unaff_EBP + 0xc));
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005d4956(*(undefined4 *)(unaff_EBP + 0xc));
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0057163b(unaff_EBP + -0x3c,unaff_EBP + -0x24,unaff_EBP + -0x30);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_0046f824(unaff_EBP + -0x140,0,0x104);
      *(undefined ***)(unaff_EBP + -0x14c) = &PTR_FUN_006664e8;
      FUN_0046f847(*(undefined4 *)(unaff_EBP + 0xc),0xffffffff);
      FUN_0046f847(s_SoundData_Shared_Sys__006cf33c,0xffffffff);
      FUN_005d48d9();
      *(undefined4 *)(unaff_EBP + -4) = 4;
      uVar3 = FUN_005e7743();
      *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x148));
      sVar6 = _strlen(s_BtnDown_WAV_006cf330);
      FUN_00412d8a(s_BtnDown_WAV_006cf330,s_BtnDown_WAV_006cf330 + sVar6);
      pvVar5 = operator_new(0x174);
      *(void **)(unaff_EBP + 8) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      if (pvVar5 != (void *)0x0) {
        piVar7 = (int *)FUN_005f7ebe();
      }
      puVar4 = (undefined4 *)*piVar7;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      (*(code *)*puVar4)();
      (**(code **)(*piVar7 + 8))();
      (**(code **)(*piVar7 + 0x14))(unaff_EBP + -0x18,0);
      (**(code **)(**(int **)(extraout_ECX + 4) + 0x2c))(piVar7);
      iVar2 = *piVar7;
      *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(unaff_EBP + 0xc);
      uVar3 = (**(code **)(iVar2 + 0x50))();
      (**(code **)(*(int *)(unaff_EBP + 8) + 0x40))(2,uVar3);
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x148));
      sVar6 = _strlen(s_BtnUp_WAV_006cf324);
      FUN_00412d8a(s_BtnUp_WAV_006cf324,s_BtnUp_WAV_006cf324 + sVar6);
      pvVar5 = operator_new(0x174);
      *(void **)(unaff_EBP + 8) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      if (pvVar5 == (void *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)FUN_005f7ebe();
      }
      puVar4 = (undefined4 *)*piVar7;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      (*(code *)*puVar4)();
      (**(code **)(*piVar7 + 8))();
      (**(code **)(*piVar7 + 0x14))(unaff_EBP + -0x18,0);
      (**(code **)(**(int **)(extraout_ECX + 4) + 0x2c))(piVar7);
      iVar2 = *piVar7;
      *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(unaff_EBP + 0xc);
      uVar3 = (**(code **)(iVar2 + 0x50))();
      (**(code **)(*(int *)(unaff_EBP + 8) + 0x40))(1,uVar3);
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x148));
      sVar6 = _strlen(s_Error_WAV_006cf318);
      FUN_00412d8a(s_Error_WAV_006cf318,s_Error_WAV_006cf318 + sVar6);
      pvVar5 = operator_new(0x174);
      *(void **)(unaff_EBP + 8) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      if (pvVar5 == (void *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)FUN_005f7ebe();
      }
      puVar4 = (undefined4 *)*piVar7;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      (*(code *)*puVar4)();
      (**(code **)(*piVar7 + 8))();
      (**(code **)(*piVar7 + 0x14))(unaff_EBP + -0x18,0);
      (**(code **)(**(int **)(extraout_ECX + 4) + 0x2c))(piVar7);
      iVar2 = *piVar7;
      *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(unaff_EBP + 0xc);
      uVar3 = (**(code **)(iVar2 + 0x50))();
      (**(code **)(*(int *)(unaff_EBP + 8) + 0x40))(0,uVar3);
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x148));
      sVar6 = _strlen(s_BtnOver_WAV_006cf30c);
      FUN_00412d8a(s_BtnOver_WAV_006cf30c,s_BtnOver_WAV_006cf30c + sVar6);
      pvVar5 = operator_new(0x174);
      *(void **)(unaff_EBP + 8) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 8;
      if (pvVar5 == (void *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)FUN_005f7ebe();
      }
      puVar4 = (undefined4 *)*piVar7;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      (*(code *)*puVar4)();
      (**(code **)(*piVar7 + 8))();
      (**(code **)(*piVar7 + 0x14))(unaff_EBP + -0x18,0);
      (**(code **)(**(int **)(extraout_ECX + 4) + 0x2c))(piVar7);
      iVar2 = *piVar7;
      *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(unaff_EBP + 0xc);
      uVar3 = (**(code **)(iVar2 + 0x50))();
      (**(code **)(*(int *)(unaff_EBP + 8) + 0x40))(3,uVar3);
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x148));
      sVar6 = _strlen(s_ScrllClk_WAV_006cf2fc);
      FUN_00412d8a(s_ScrllClk_WAV_006cf2fc,s_ScrllClk_WAV_006cf2fc + sVar6);
      pvVar5 = operator_new(0x174);
      *(void **)(unaff_EBP + 8) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 9;
      if (pvVar5 == (void *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)FUN_005f7ebe();
      }
      puVar4 = (undefined4 *)*piVar7;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      (*(code *)*puVar4)();
      (**(code **)(*piVar7 + 8))();
      (**(code **)(*piVar7 + 0x14))(unaff_EBP + -0x18,0);
      (**(code **)(**(int **)(extraout_ECX + 4) + 0x2c))(piVar7);
      iVar2 = **(int **)(unaff_EBP + 0xc);
      uVar3 = (**(code **)(*piVar7 + 0x50))();
      (**(code **)(iVar2 + 0x40))(4,uVar3);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

