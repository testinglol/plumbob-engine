
void __fastcall FUN_00478a7b(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 local_2 [2];
  
  puVar1 = (undefined1 *)param_1[1];
  puVar3 = (undefined1 *)*param_1;
  if (puVar3 != puVar1) {
    puVar2 = puVar3 + 2;
    do {
      if (puVar2 != local_2) {
        *puVar3 = 0x7f;
        puVar2[-1] = 0x7f;
        *puVar2 = 0x7f;
        puVar2[1] = 0x7f;
      }
      puVar3 = puVar3 + 4;
      puVar2 = puVar2 + 4;
    } while (puVar3 != puVar1);
  }
  return;
}

