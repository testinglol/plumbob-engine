
undefined4 __thiscall FUN_005fc4d2(int *param_1,undefined4 *param_2)

{
  LPVOID *ppv;
  int *piVar1;
  HRESULT HVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  WCHAR local_298 [260];
  undefined4 local_90 [32];
  int *local_10;
  int *local_c;
  uint local_8;
  
  (**(code **)(*param_1 + 0xc))();
  FUN_005d499c(param_2);
  ppv = (LPVOID *)(param_1 + 0x60);
  HVar2 = CoCreateInstance((IID *)&DAT_00689000,(LPUNKNOWN)0x0,3,(IID *)&DAT_00689010,ppv);
  if ((-1 < HVar2) &&
     (iVar3 = (*(code *)**(undefined4 **)*ppv)(*ppv,&DAT_00688ff0,param_1 + 0x61), -1 < iVar3)) {
    piVar1 = param_1 + 0x62;
    iVar3 = (*(code *)**(undefined4 **)*ppv)(*ppv,&DAT_00688fe0,piVar1);
    if (-1 < iVar3) {
      (**(code **)(*(int *)*piVar1 + 4))((int *)*piVar1);
      piVar1 = (int *)*piVar1;
      iVar3 = (**(code **)(*piVar1 + 0x34))(piVar1,DAT_006fe8cc,0xc00,piVar1);
      if (-1 < iVar3) {
        uVar4 = 0;
        MultiByteToWideChar(0,0,(LPCSTR)*param_2,-1,local_298,0x104);
        iVar3 = (**(code **)(*(int *)*ppv + 0x34))(*ppv,local_298,0);
        if (((-1 < iVar3) &&
            (iVar3 = (*(code *)**(undefined4 **)*ppv)(*ppv,&DAT_00688fd0,param_1 + 99), -1 < iVar3))
           && (iVar3 = (**(code **)(*(int *)*ppv + 0x14))(*ppv,&local_c), -1 < iVar3)) {
          local_8 = 0;
          iVar3 = (**(code **)(*local_c + 0xc))(local_c,0x20,local_90,&local_8);
          if (-1 < iVar3) {
            if (local_8 != 0) {
              puVar5 = local_90;
              do {
                iVar3 = (*(code *)**(undefined4 **)*puVar5)
                                  ((undefined4 *)*puVar5,&DAT_00688fc0,&local_10);
                if (-1 < iVar3) {
                  iVar3 = (**(code **)(*local_10 + 0x24))(local_10,DAT_006fe8cc,0);
                  if (iVar3 < 0) goto LAB_005fc673;
                  (**(code **)(*local_10 + 8))(local_10);
                }
                uVar4 = uVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar4 < local_8);
            }
            if (local_c != (int *)0x0) {
              (**(code **)(*local_c + 8))(local_c);
            }
            uVar4 = 0;
            if (local_8 != 0) {
              puVar5 = local_90;
              do {
                (**(code **)(*(int *)*puVar5 + 8))((int *)*puVar5);
                uVar4 = uVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar4 < local_8);
            }
            *(undefined1 *)(param_1 + 0x5f) = 1;
            return 1;
          }
        }
      }
    }
  }
LAB_005fc673:
  (**(code **)(*param_1 + 0xc))();
  return 0;
}

