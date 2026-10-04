
void FUN_004e0ffc(void)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  DWORD DVar6;
  int unaff_EBP;
  int *piVar7;
  bool bVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  bVar8 = DAT_006f2354 == (code *)0x0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (bVar8) {
    FUN_004e0eba(s__SymLoadModule_was_NULL__006c9828);
  }
  else {
    cVar2 = FUN_004e1113(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0xc));
    if (cVar2 == '\0') {
      FUN_004e0eba(s_Could_not_load_modules_using_TH3_006c97f0);
      FUN_004e1314(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8)
                  );
    }
    if (*(int *)(unaff_EBP + -0x18) != *(int *)(unaff_EBP + -0x14)) {
      piVar7 = (int *)(*(int *)(unaff_EBP + -0x18) + 0xc);
      do {
        pvVar3 = operator_new((piVar7[-2] - piVar7[-3]) + 1);
        FUN_006358b0(pvVar3,piVar7[-3]);
        pvVar4 = operator_new((piVar7[1] - *piVar7) + 1);
        FUN_006358b0(pvVar4,*piVar7);
        iVar5 = (*DAT_006f2354)(*(undefined4 *)(unaff_EBP + 8),0,pvVar3,pvVar4,piVar7[3],piVar7[4]);
        if (iVar5 == 0) {
          DVar6 = GetLastError();
          FUN_004e0eba(s_Error__lu_loading_symbols_for____006c97c8,DVar6);
        }
        else {
          FUN_004e0eba(s_Symbols_loaded____s__006c97b0,*piVar7);
        }
        FUN_006321f0(pvVar3);
        FUN_006321f0(pvVar4);
        piVar1 = piVar7 + 5;
        piVar7 = piVar7 + 8;
      } while (piVar1 != *(int **)(unaff_EBP + -0x14));
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004e151e();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

