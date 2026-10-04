
void FUN_004e0360(void)

{
  int iVar1;
  uint uVar2;
  LPCVOID lpAddress;
  char cVar3;
  DWORD DVar4;
  HANDLE pvVar5;
  int iVar6;
  LPCVOID lpAddress_00;
  int unaff_EBP;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined *puVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  uVar9 = *(undefined4 *)(unaff_EBP + 0xc);
  FUN_004e066d(uVar9,s__________________________________006c8fdc);
  if (*(char *)(unaff_EBP + 0x10) == '\0') {
    pcVar10 = s_Address_Size_Owner_006c8f54;
  }
  else {
    FUN_004e066d(uVar9,s_RW_read_write_RO_read_only_EX_ex_006c8f90);
    pcVar10 = s_Address_Size_Attribute_Owner_006c8f6c;
  }
  FUN_004e066d(uVar9,pcVar10);
  iVar6 = *(int *)(unaff_EBP + 8);
  iVar1 = *(int *)(iVar6 + 0xc);
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  FUN_004ed1bd();
  uVar7 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  if (iVar1 != 0) {
    do {
      uVar2 = *(uint *)(iVar6 + 0x10 + uVar7 * 4);
      if (uVar2 == 0) {
        uVar7 = uVar7 + 1;
        *(uint *)(unaff_EBP + -0x20) = uVar7;
      }
      else {
        *(uint *)(unaff_EBP + -0x14) = uVar2 & 0xfff;
        lpAddress_00 = (LPCVOID)(uVar2 & 0xfffff000);
        VirtualQuery(lpAddress_00,(PMEMORY_BASIC_INFORMATION)(unaff_EBP + -0x3c),0x1c);
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x38);
        *(undefined4 *)(unaff_EBP + -0x18) = 1;
        if (*(char *)(unaff_EBP + 0x10) == '\0') {
          uVar7 = uVar7 + 1;
          if (uVar7 < *(uint *)(unaff_EBP + -0x1c)) {
            puVar8 = (undefined4 *)(iVar6 + 0x10 + uVar7 * 4);
            do {
              if ((LPCVOID)*puVar8 != (LPCVOID)0x0) {
                VirtualQuery((LPCVOID)*puVar8,(PMEMORY_BASIC_INFORMATION)(unaff_EBP + -0x3c),0x1c);
                if (*(int *)(unaff_EBP + -0x38) != *(int *)(unaff_EBP + -0x10)) break;
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
              }
              uVar7 = uVar7 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar7 < *(uint *)(unaff_EBP + -0x1c));
          }
        }
        else {
          uVar7 = uVar7 + 1;
          if (uVar7 < *(uint *)(unaff_EBP + -0x1c)) {
            puVar8 = (undefined4 *)(iVar6 + 0x10 + uVar7 * 4);
            do {
              lpAddress = (LPCVOID)*puVar8;
              if (((lpAddress == (LPCVOID)0x0) ||
                  (((uint)lpAddress & 0xfff) != *(uint *)(unaff_EBP + -0x14))) ||
                 (VirtualQuery(lpAddress,(PMEMORY_BASIC_INFORMATION)(unaff_EBP + -0x3c),0x1c),
                 *(int *)(unaff_EBP + -0x38) != *(int *)(unaff_EBP + -0x10))) break;
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
              uVar7 = uVar7 + 1;
              puVar8 = puVar8 + 1;
            } while (uVar7 < *(uint *)(unaff_EBP + -0x1c));
          }
        }
        *(undefined1 *)(unaff_EBP + -0xbc) = 0;
        iVar1 = *(int *)(unaff_EBP + -0x20);
        puVar8 = (undefined4 *)(unaff_EBP + -0xbb);
        for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        *(undefined2 *)puVar8 = 0;
        *(undefined1 *)((int)puVar8 + 2) = 0;
        if (((byte)*(undefined4 *)(unaff_EBP + -0x14) & 5) == 5) {
          puVar11 = &DAT_006c8f50;
LAB_004e04e7:
          FUN_006358c0(unaff_EBP + -0xbc,puVar11);
        }
        else {
          if ((*(byte *)(unaff_EBP + -0x14) & 1) != 0) {
            FUN_006358c0(unaff_EBP + -0xbc,&DAT_006c8f4c);
          }
          if ((*(byte *)(unaff_EBP + -0x14) & 2) != 0) {
            FUN_006358c0(unaff_EBP + -0xbc,&DAT_006c8f48);
          }
          if ((*(byte *)(unaff_EBP + -0x14) & 4) != 0) {
            puVar11 = &DAT_006c8f44;
            goto LAB_004e04e7;
          }
        }
        if ((*(byte *)(unaff_EBP + -0x13) & 1) != 0) {
          FUN_006358c0(unaff_EBP + -0xbc,&DAT_006c8f40);
        }
        *(undefined1 *)(unaff_EBP + -0x1c0) = 0;
        if (*(int *)(unaff_EBP + -0x10) == 0) {
          FUN_006358b0(unaff_EBP + -0x1c0,s_<unknown>_006c8f34);
        }
        else {
          DVar4 = GetModuleFileNameA(*(HMODULE *)(unaff_EBP + -0x10),(LPSTR)(unaff_EBP + -0x1c0),
                                     0x104);
          if (DVar4 == 0) {
            cVar3 = FUN_004ed225(*(undefined4 *)(unaff_EBP + -0x10));
            if (cVar3 == '\0') {
              iVar6 = unaff_EBP + -0x1c0;
              uVar12 = 0x104;
              uVar9 = *(undefined4 *)(unaff_EBP + -0x10);
              pvVar5 = GetCurrentProcess();
              iVar6 = (*DAT_006f2224)(pvVar5,uVar9,iVar6,uVar12);
              if (iVar6 != 0) goto LAB_004e0591;
              pcVar10 = s_VirtualAlloc_Stack_Other_006c8f10;
            }
            else {
              pcVar10 = &DAT_006c8f2c;
            }
            wsprintfA((LPSTR)(unaff_EBP + -0x1c0),pcVar10);
          }
        }
LAB_004e0591:
        if (*(char *)(unaff_EBP + 0x10) == '\0') {
          FUN_004e066d(*(undefined4 *)(unaff_EBP + 0xc),s__08X__5uK__s_006c8eec,lpAddress_00,
                       DAT_006f2218 * *(int *)(unaff_EBP + -0x18),unaff_EBP + -0x1c0);
        }
        else {
          FUN_004e066d(*(undefined4 *)(unaff_EBP + 0xc),s__08X__5uK___9s__s_006c8efc,lpAddress_00,
                       DAT_006f2218 * *(int *)(unaff_EBP + -0x18),unaff_EBP + -0xbc);
        }
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + (uVar7 - iVar1);
        iVar6 = *(int *)(unaff_EBP + 8);
        uVar7 = *(uint *)(unaff_EBP + -0x20);
      }
    } while (uVar7 < *(uint *)(unaff_EBP + -0x1c));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

