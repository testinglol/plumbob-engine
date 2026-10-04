
void __thiscall FUN_004b91d9(int param_1,undefined4 param_2,char param_3)

{
  void *pvVar1;
  HDC hdc;
  int iVar2;
  HPALETTE pHVar3;
  LOGPALETTE local_408 [123];
  tagPALETTEENTRY local_2c [10];
  
  FUN_004b91b0();
  *(undefined4 *)(param_1 + 0xc) = 0x100;
  pvVar1 = operator_new(0x400);
  *(void **)(param_1 + 8) = pvVar1;
  *(char *)(param_1 + 0x10) = param_3;
  hdc = GetDC((HWND)0x0);
  local_408[0].palVersion = 0x300;
  local_408[0].palNumEntries = 0x100;
  FUN_005a92b0(local_408[0].palPalEntry,param_2,0x400);
  if (param_3 == '\0') {
    iVar2 = 0;
    do {
      (&local_408[0].palPalEntry[0].peFlags)[iVar2] = '\x05';
      *(undefined4 *)(*(int *)(param_1 + 8) + iVar2) =
           *(undefined4 *)(&local_408[0].palPalEntry[0].peRed + iVar2);
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x400);
  }
  else {
    GetSystemPaletteEntries(hdc,0,10,local_408[0].palPalEntry);
    GetSystemPaletteEntries(hdc,0xf6,10,local_2c);
    iVar2 = 0;
    do {
      if ((iVar2 < 0x28) || (0x3d7 < iVar2)) {
        (&local_408[0].palPalEntry[0].peFlags)[iVar2] = '\0';
      }
      else {
        (&local_408[0].palPalEntry[0].peFlags)[iVar2] = '\x04';
      }
      *(undefined4 *)(*(int *)(param_1 + 8) + iVar2) =
           *(undefined4 *)(&local_408[0].palPalEntry[0].peRed + iVar2);
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x400);
  }
  pHVar3 = CreatePalette(local_408);
  *(HPALETTE *)(param_1 + 4) = pHVar3;
  ReleaseDC((HWND)0x0,hdc);
  return;
}

