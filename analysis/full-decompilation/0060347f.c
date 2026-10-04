
char FUN_0060347f(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  char cVar4;
  HMODULE hModule;
  FARPROC pFVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uVar8;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = DAT_006fe8cc;
  piVar1 = (int *)(extraout_ECX + -4);
  *(undefined1 *)(unaff_EBP + -0x10) = 1;
  DAT_006fed70 = piVar1;
  cVar4 = (**(code **)(*piVar1 + 0xc))();
  if (cVar4 != '\0') {
    cVar4 = (**(code **)(*piVar1 + 8))();
    if (cVar4 == '\0') {
      hModule = LoadLibraryA(s_dsound_dll_006d9190);
      *(undefined4 *)(extraout_ECX + 0xd8) = hModule;
      pFVar5 = GetProcAddress(hModule,s_DirectSoundCreate_006d917c);
      *(FARPROC *)(unaff_EBP + -0x14) = pFVar5;
      pFVar5 = GetProcAddress(*(HMODULE *)(extraout_ECX + 0xd8),s_DirectSoundEnumerateA_006d9164);
      if ((*(int *)(unaff_EBP + -0x14) == 0) || (pFVar5 == (FARPROC)0x0)) {
        cVar4 = '\0';
        goto LAB_006036a1;
      }
      *(int *)(unaff_EBP + -0x1c) = extraout_ECX + -4;
      iVar6 = (*pFVar5)(&LAB_00604128,extraout_ECX + -4);
      if (iVar6 == 0) {
        pvVar7 = operator_new(0x174);
        *(void **)(unaff_EBP + -0x20) = pvVar7;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar7 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_005f7ebe();
        }
        *(int *)(extraout_ECX + 0x54) = iVar6;
        *(undefined2 *)(iVar6 + 0xa8) = 1;
        iVar6 = *(int *)(extraout_ECX + 0x54);
        uVar3 = *(undefined2 *)(extraout_ECX + 100);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar2 = (undefined4 *)(extraout_ECX + 0x4c);
        *(undefined2 *)(iVar6 + 0xaa) = uVar3;
        *(undefined4 *)(*(int *)(extraout_ECX + 0x54) + 0xac) = *(undefined4 *)(extraout_ECX + 0x60)
        ;
        *(uint *)(*(int *)(extraout_ECX + 0x54) + 0xb0) =
             (*(uint *)(extraout_ECX + 0x5c) >> 3) * *(int *)(extraout_ECX + 100) *
             *(int *)(extraout_ECX + 0x60);
        *(short *)(*(int *)(extraout_ECX + 0x54) + 0xb4) =
             (short)(*(uint *)(extraout_ECX + 0x5c) >> 2);
        *(undefined2 *)(*(int *)(extraout_ECX + 0x54) + 0xb6) = *(undefined2 *)(extraout_ECX + 0x5c)
        ;
        *(undefined2 *)(*(int *)(extraout_ECX + 0x54) + 0xb8) = 0;
        iVar6 = (**(code **)(unaff_EBP + -0x14))(0,puVar2,0);
        if (iVar6 != 0) {
          *puVar2 = 0;
          goto LAB_00603640;
        }
        iVar6 = (**(code **)(*(int *)*puVar2 + 0x18))
                          ((int *)*puVar2,*(undefined4 *)(unaff_EBP + -0x18),2);
        if (iVar6 != 0) goto LAB_00603640;
        pvVar7 = operator_new(0xc);
        *(void **)(unaff_EBP + -0x20) = pvVar7;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar7 == (void *)0x0) {
          uVar8 = 0;
        }
        else {
          uVar8 = FUN_00607a0b();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined4 *)(extraout_ECX + 0x6c) = uVar8;
        *(undefined1 *)(extraout_ECX + 0x4b) = 0;
        *(undefined4 *)(extraout_ECX + 0x70) = 0;
        iVar6 = (**(code **)(*(int *)*puVar2 + 0x10))
                          ((int *)*puVar2,*(undefined4 *)(extraout_ECX + 0x50));
        if (iVar6 != 0) goto LAB_00603640;
        DAT_006fed6c = *puVar2;
        cVar4 = (**(code **)(**(int **)(extraout_ECX + 0x54) + 0xec))();
        if (cVar4 == '\0') goto LAB_00603640;
        DAT_006fed74 = *(undefined4 *)(*(int *)(extraout_ECX + 0x54) + 0x80);
        piVar1 = *(int **)(*(int *)(extraout_ECX + 0x54) + 0x80);
        iVar6 = (**(code **)(*piVar1 + 0x30))(piVar1,0,0,1);
        if (iVar6 != 0) goto LAB_00603640;
      }
      else {
LAB_00603640:
        piVar1 = *(int **)(extraout_ECX + 0x54);
        if ((piVar1 != (int *)0x0) && (piVar1[0x20] != 0)) {
          (**(code **)(*piVar1 + 0xf0))();
          *(undefined4 *)(*(int *)(extraout_ECX + 0x54) + 0x80) = 0;
        }
        piVar1 = *(int **)(extraout_ECX + 0x4c);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          DAT_006fed6c = 0;
          *(undefined4 *)(extraout_ECX + 0x4c) = 0;
        }
        *(undefined1 *)(unaff_EBP + -0x10) = 0;
      }
      piVar1 = *(int **)(unaff_EBP + -0x1c);
      (**(code **)(*piVar1 + 0xb0))(*(undefined4 *)(unaff_EBP + -0x10));
      cVar4 = *(char *)(unaff_EBP + -0x10);
      if (cVar4 != '\0') goto LAB_006036a1;
      (**(code **)(*piVar1 + 0x98))(0);
    }
  }
  cVar4 = '\x01';
LAB_006036a1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar4;
}

