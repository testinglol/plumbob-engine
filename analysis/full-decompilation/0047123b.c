
void __fastcall FUN_0047123b(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x6c);
  if (puVar1 != *(undefined4 **)(param_1 + 0x70)) {
    do {
      for (piVar2 = (int *)*puVar1; piVar2 != (int *)puVar1[1]; piVar2 = piVar2 + 3) {
        if (*piVar2 != 0) {
          FUN_006321f0(*piVar2);
        }
        if (piVar2[1] != 0) {
          FUN_006321f0(piVar2[1]);
        }
      }
      FUN_004717fa(*puVar1,puVar1[1]);
      puVar1 = puVar1 + 3;
    } while (puVar1 != *(undefined4 **)(param_1 + 0x70));
  }
  return;
}

