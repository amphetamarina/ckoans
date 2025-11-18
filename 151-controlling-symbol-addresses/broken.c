#include <stdio.h>
#include <stdint.h>

// Simulating linker-defined symbols
// In real code, these would come from linker script
char simulated_text_start[1] = {0};
char simulated_text_end[1] = {0};
char simulated_data_start[1] = {0};
char simulated_data_end[1] = {0};

// Mock addresses for demonstration
#define MOCK_TEXT_START 0x400000
#define MOCK_TEXT_END   0x401000
#define MOCK_DATA_START 0x600000
#define MOCK_DATA_END   0x601000

void show_symbol_addresses(void) {
    printf("Linker-Defined Symbol Addresses\n");
    printf("================================\n\n");

    // In real code: extern char _text_start[], _text_end[];
    // size_t text_size = _text_end - _text_start;

    printf("Text section:\n");
    printf("  Start: 0x%lx\n", (unsigned long)MOCK_TEXT_START);
    printf("  End:   0x%lx\n", (unsigned long)MOCK_TEXT_END);

    // BUG: Wrong size calculation
    size_t text_size = (MOCK_TEXT_END - MOCK_TEXT_START) / 2;
    printf("  Size:  0x%lx bytes\n", (unsigned long)text_size);

    printf("\nData section:\n");
    printf("  Start: 0x%lx\n", (unsigned long)MOCK_DATA_START);
    printf("  End:   0x%lx\n", (unsigned long)MOCK_DATA_END);

    // Correct size calculation
    size_t data_size = MOCK_DATA_END - MOCK_DATA_START;
    printf("  Size:  0x%lx bytes\n", (unsigned long)data_size);
}

void demonstrate_location_counter(void) {
    printf("\nLocation Counter (.) in Linker Scripts:\n");
    printf("  - Current address in output section\n");
    printf("  - Can assign: _symbol = .;\n");
    printf("  - Can align: . = ALIGN(4096);\n");
    printf("  - Can advance: . += 0x1000;\n");
}

int main(void) {
    show_symbol_addresses();
    demonstrate_location_counter();

    printf("\nLinker scripts provide fine-grained address control\n");
    printf("Essential for embedded systems and bootloaders\n");

    return 0;
}
